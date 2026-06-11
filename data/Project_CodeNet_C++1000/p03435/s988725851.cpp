#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a(3), b(3);
    vector<vector<int> > c(3, vector<int>(3, 0));
    bool is_correct;

    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){
            cin >> c.at(i).at(j);
        }

    }

    for(a.at(0) = 0; a.at(0) <= c.at(0).at(0); a.at(0)++){
        is_correct = true;
        b.at(0) = c.at(0).at(0) - a.at(0);
        b.at(1) = c.at(0).at(1) - a.at(0);
        b.at(2) = c.at(0).at(2) - a.at(0);
        a.at(1) = c.at(1).at(0) - b.at(0);
        a.at(2) = c.at(2).at(0) - b.at(0);

        for(int i = 1; i < 3; i++){

            for(int j = 1; j < 3; j++){
                if(c.at(i).at(j) != a.at(i) + b.at(j)){
                    is_correct = false;
                    break;
                }

            }

            if(!is_correct) break;
        }
        if(is_correct) break;
    }
    if(is_correct) cout << "Yes" << endl;
    else cout << "No" << endl;
}