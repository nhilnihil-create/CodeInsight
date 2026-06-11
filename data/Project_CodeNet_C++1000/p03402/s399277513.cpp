#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

int main(){
    
    int a,b;
    bool bre = false;
    char g[200][200];
    cin >> a>>b;
    a--;b--;
    rep(i,50){
        rep(j,100){
            g[i][j]='#';
            g[i+50][j]='.';
        }
    }
    
    for(int h = 1;h<49;h+=2){
        for(int w = 1;w<99;w+=2){
            if(a==0){
                bre = true;
                break;
            }
            g[h][w] = '.';
            a--;
        }
        if(bre)break;
    }
    
    bre = false;
    
    for(int h = 51;h<100;h+=2){
        for(int w = 1;w<99;w+=2){
            if(b==0){
                bre = true;
                break;
            }
            g[h][w] = '#';
            b--;
        }
        if(bre)break;
    }
    
    cout << 100<<' '<<100<<endl;
    
    rep(i,100){
        rep(j,100){
            cout << g[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
