#include<bits/stdc++.h>
using namespace std;
const long long EVENINF = 100100100100100;  //でかい偶数
//二冪
//ケンチョンさんの写経

int main(){

    int n; cin >> n;
    vector<pair<long long, long long> > pos(n); //pos := position
    for(int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;

    //x[i] + y[i]のパリティが不一致なら -1 を出力
    bool par1 = (pos[0].first + pos[0].second + EVENINF) % 2;
    for(int i = 0; i < n; i++){
        bool par2 = (pos[i].first + pos[i].second + EVENINF) % 2;
        pos[i] = {pos[i].first + pos[i].second, pos[i].first - pos[i].second};
        if(par1 != par2){
            cout << -1 << endl;
            return 0;
        }
    }


    //ロボットアームを構成
    vector<long long> d;
    for(int i = 30; i >= 0; i--) d.push_back(1LL << i);
    if(!par1) d.push_back(1LL);
    
    //ロボットアームの情報を出力
    cout << d.size() << endl;
    for(int i = 0; i < (int)d.size(); i++){
        if(i + 1 == (int)d.size()) cout << d[i] << endl;
        else cout << d[i] << " ";
    }

    for(int i = 0; i < n; i++){
        int xdir, ydir;
        long long xsum = 0LL, ysum = 0LL;
        for(int j = 0; j < (int)d.size(); j++){
            
            //cout << xsum << " " << ysum << endl;

            if(xsum <= pos[i].first){
                xdir = 1;
                xsum += d[j];
            }else{
                xdir = -1;
                xsum -= d[j];
            }

            if(ysum <= pos[i].second){
                ydir = 1;
                ysum += d[j];
            }else{
                ydir = -1;
                ysum -= d[j];
            }
            
            if (xdir == 1 && ydir == 1) cout << "R";
            else if (xdir == 1 && ydir == -1) cout << "U";
            else if (xdir == -1 && ydir == -1) cout << "L";
            else cout << "D";

        }
        //cout << "( " << xsum << ", " << ysum << ")" << endl;
        cout << endl;
    }

    return 0;
}