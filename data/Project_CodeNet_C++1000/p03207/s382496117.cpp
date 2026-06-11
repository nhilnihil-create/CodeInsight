#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n;
    cin >> n;
    int m=0;
    int sum=0;
    rp(i,n){
        int p;
        cin >> p;
        sum += p;
        m=max(m,p);
    }
    cout << sum-m/2 << endl;
}