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

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int M=0;
    int m=0;
    int Mitr=1,mitr=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=0){
            if(M<=a[i]){
                M=a[i];
                Mitr=i+1;
            }
        }else{
            if(m>=a[i]){
                m=a[i];
                mitr=i+1;
            }
        }
    }
    int ans=0;
    vector<int> x(0),y(0);
    if(M>abs(m)){
        for(int i=1;i<=n;i++){
            x.push_back(Mitr);
            y.push_back(i);
            ans++;
        }
        for(int i=1;i<=n-1;i++){
            x.push_back(i);
            y.push_back(i+1);
            ans++;
        }
    }else{
        for(int i=1;i<=n;i++){
            x.push_back(mitr);
            y.push_back(i);
            ans++;
        }
        for(int i=n;i>=2;i--){
            x.push_back(i);
            y.push_back(i-1);
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
}