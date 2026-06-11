#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
char s[100][100];

int main(){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            s[i][j]='#';
        }
    }
    for(int i=50;i<100;i++){
        for(int j=0;j<100;j++){
            s[i][j]='.';
        }
    }
    while(a){
        for(int i=0;i<50;i+=2){
            for(int j=0;j<50;j++){
                s[i][2*j]='.';
                a--;
                if(a==0) break;
            }
            if(a==0) break;
        }
        if(a==0) break;
    }
    while(b){
        for(int i=99;i>=50;i-=2){
            for(int j=0;j<50;j++){
                s[i][2*j]='#';
                b--;
                if(b==0) break;
            }
            if(b==0) break;
        }
        if(b==0) break;
    }
    cout<<100<<" "<<100<<endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}