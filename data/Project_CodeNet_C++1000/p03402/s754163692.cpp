#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int i=(m);(i)<(n);(i)++)
typedef long long ll;

int main(){
    int a,b;
    cin >> a >> b;
    char map[100][100];
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            map[i][j]='#';
        }
    }
    for(int i=50;i<100;i++){
        for(int j=0;j<100;j++){
            map[i][j]='.';
        }
    }
    a--;b--;
    for(int i=0;i<49;i++){
        if(!a)break;
        for(int j=0;j<100;j++){
            if(!a)break;
            if(i%2==0&&j%2==0){
                map[i][j]='.';
                a--;
            }
        }
    }
    for(int i=51;i<100;i++){
        if(!b)break;
        for(int j=0;j<100;j++){
            if(!b)break;
            if(i%2==0&&j%2==0){
                map[i][j]='#';
                b--;
            }
        }
    }
    cout << 100 << " " << 100 << endl;
    rep(i,100){
        rep(j,100)cout << map[i][j];
        cout << endl;
    }
    return 0;
}