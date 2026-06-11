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
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 2000;

int main(){
    
    int n,x,y;
    int num[maxn];
    
    cin >> n>>x>>y;
    rep(i,n){
        cin >> num[i];
    }
    
    if(n==1){
        cout << abs(num[0]-y)<<endl;
    }else{
        cout << max(abs(num[n-1]-y),abs(num[n-1]-num[n-2]))<<endl;
    }
    
    return 0;
}
