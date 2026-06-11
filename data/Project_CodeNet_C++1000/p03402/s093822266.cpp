#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define MOD  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
#define ps push_back
double pi = 3.141592653589793;
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
//ここから始めよう
signed main(){
    int a,b;cin>>a>>b;
    cout<<100<<" "<<100<<endl;
    rep(i,0,50){
        rep(j,0,100){
            if(i%2==0&&(i+j)%2==0&&a>1){
                cout<<'.';a--;
            }else cout<<'#';
        }cout<<endl;
    }
    rep(i,0,50){
        rep(j,0,100){
            if(i%2==1&&(i+j)%2==0&&b>1){
                cout<<'#';b--;
            }else cout<<'.';
        }cout<<endl;
    }
    return 0;
}