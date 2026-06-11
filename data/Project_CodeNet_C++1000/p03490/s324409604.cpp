#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    int x,y;
    cin >> s >> x >> y;
    vector<int> move_x,move_y;
    bool x_frag=true;
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='T'){
            if(x_frag){
                move_x.push_back(count);
                x_frag=false;
            }
            else{
                move_y.push_back(count);
                x_frag=true;
            }
            count=0;
            continue;
        }
        if(x_frag){
            count++;
            if(i==s.size()-1) move_x.push_back(count);
        }
        else{
            count++;
            if(i==s.size()-1) move_y.push_back(count);
        }
    }
    
    int now_x=move_x[0], now_y=0;
    move_x[0] = 0;
    sort(move_x.begin(),move_x.end(),greater<int>());
    sort(move_y.begin(),move_y.end(),greater<int>());

    for(int i=0;i<move_x.size();i++){
        if(now_x <= x) now_x += move_x[i];
        else now_x -= move_x[i];
    }
    for(int i=0;i<move_y.size();i++){
        if(now_y <= y) now_y += move_y[i];
        else now_y -= move_y[i];
    }
    if(now_x==x&&now_y==y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}