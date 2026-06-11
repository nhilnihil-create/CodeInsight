#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <cstdlib>
typedef long long ll;


#define REP(i, N) for (int i = 0; i < (N); i++)
#define REPP(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define VSORT(c) sort((c).begin(),(c).end())
#define SZ(x) ((int)(x).size())
//vvintを作る　マクロで　 #define vvint(N,M) vector<vector<int>>

using namespace std;


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> str(N);
    for(int i = 0; i < N;i++){
        cin >> str[i];
    }
    int cntA = 0,cntB = 0,cntAB=0;
    int ans = 0;
    for(int i = 0; i < N;i++){
        if(str[i][0] == 'B' && str[i][str[i].length()-1] == 'A') cntAB++;
        else if(str[i][0] == 'B') cntB++;
        else if(str[i][str[i].length()-1] == 'A') cntA++;
        
        for(int l = 0; l < str[i].length();l++){
            if(str[i][l] == 'A' && l != str[i].length()-1){
                if(str[i][l+1] == 'B'){
                    ans++;
                }
            }
        }
    }
    ans += cntAB != 0 ? cntAB-1 : 0;
    if(cntAB != 0 && cntA > 0){
        ans++;
        cntA--;
    }
    if(cntAB != 0 && cntB > 0){
        ans++;
        cntB--;
    }
    ans += min(cntA,cntB);
    
    cout << ans << endl;

    // int N;
    // cin >> N;
    // vector<int> row,mi,pu,a,b;
    // int r;


    // for(int i = 0; i < N;i++){
    //     cin >> r;
    //     if(r < 0){
    //         mi.push_back(r);
    //     }else{
    //         pu.push_back(r);
    //     }
    //     row.push_back(r);
    // }
    // VSORT(pu);
    // VSORT(mi);
    // VSORT(row);
    // int sum = 0;
    // if(mi.size() != 0){
    //     if(pu.size() != 0){
    //         for(int i = 0; i < N;i++){
    //             sum += abs(row[i]);
    //         }
    //         for(int i = pu.size()-1; i > 0;i--){
    //             int tmp = mi[mi.size()-1];
    //             mi.pop_back();
    //             a.push_back(tmp);
    //             b.push_back(pu[i]);
    //             mi.push_back(tmp-pu[i]);
    //             pu.pop_back();
    //         }
    //         int tmp = pu[0];
    //         for(int i = 0; i < mi.size();i++){
    //             a.push_back(tmp);
    //             b.push_back(mi[i]);
    //             tmp -= mi[i];
    //         }
    //         cout << sum << endl;
    //         for(int i = 0; i < a.size();i++){
    //             cout << a[i] << " " << b[i] << endl;
    //         }
    //         return 0;


    //     }else{
    //         for(int i = 0; i < N-1;i++){
    //             sum += abs(row[i]);
    //         }
    //         sum += row[N-1];

    //         int tmp = mi[mi.size()-1];
    //         for(int i = 0; i < mi.size()-1;i++){
    //             a.push_back(tmp);
    //             b.push_back(mi[i]);
    //             tmp -= mi[i];
    //         }
         
    //     }
    // }else{
    //     if(pu.size() != 0){
    //         for(int i = 1; i < N;i++){
    //             sum += abs(row[i]);
    //         }
    //         sum -= row[0];

    //         int tmp = pu[0];
    //         for(int i = 1; i < pu.size()-1;i++){
    //             a.push_back(tmp);
    //             b.push_back(pu[i]);
    //             tmp -= pu[i];
    //         }
    //         b.push_back(tmp);
    //         a.push_back(pu[pu.size()-1]);
    //     }
    // }
    // cout << sum << endl;
    // for(int i = 0; i < a.size();i++){
    //     cout << a[i] << " " << b[i] << endl;
    // }
    
    return 0;
}