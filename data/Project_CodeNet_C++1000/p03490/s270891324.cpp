#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool x_true[16010][8010];
bool y_true[16010][8010];
vector<int> to_x;
vector<int> to_y;


int main()
{
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    bool switcher = true;//true:x
    bool check = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'T'){
            check = false;
            if(switcher == true){
                switcher = false;
            } else {
                switcher = true;
            }
        }
        if(s[i] == 'F'){
            if(check == true){
                x--;
                continue;
            }
            if(switcher == true){
                if(s[i - 1] == 'T'){
                    to_x.push_back(1);
                } else {
                    to_x[to_x.size() - 1]++;
                }
                //cout << to_x[0] << endl;
            }
            if(switcher == false){
                if(s[i - 1] == 'T'){
                    to_y.push_back(1);
                } else {
                    to_y[to_y.size() - 1]++;
                }
            }
        }
    }
    for(int i = 0; i <= 16005; i++){
        x_true[i][0] = false;
        y_true[i][0] = false;
    }
    x_true[8000][0] = true;
    y_true[8000][0] = true;
    for(int i = 1; i <= to_x.size(); i++){
        for(int j = 0; j <= 16005; j++){
            if(j >= to_x[i - 1]){
                if(x_true[j - to_x[i - 1]][i - 1]){
                    x_true[j][i]= true;
                    continue;
                }
            }
            if(j <= 16005 - to_x[i - 1]){
                if(x_true[j + to_x[i - 1]][i - 1]){
                    x_true[j][i] = true;
                    continue;
                }
            }
            x_true[j][i] = false;
        }
    }
    for(int i = 1; i <= to_y.size(); i++){
        for(int j = 0; j <= 16005; j++){
            if(j >= to_y[i - 1]){
                if(y_true[j - to_y[i - 1]][i - 1]){
                    y_true[j][i] = true;
                    //cout << "y_true" << j << " " << i << " = true;" << endl;
                    continue;
                }
            }
            if(j <= 16005 - to_y[i - 1]){
                if(y_true[j + to_y[i - 1]][i - 1]){
                    y_true[j][i] = true;
                    //cout << "x_true" << j << " " << i << " = true;" << endl;
                    continue;
                }
            }
            y_true[j][i] = false;
        }
    }
    if(x_true[x +8000][to_x.size()] && y_true[y + 8000][to_y.size()]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}