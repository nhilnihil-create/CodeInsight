#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    long long sum = abs(a.at(0))+abs(a.at(n-1));
    rep(i, n-1){
        sum += abs(a.at(i)-a.at(i+1));
    }
    int tmp = 0;
    rep(i, n){
        if(i==0)
        tmp = abs(a.at(0))+abs(a.at(0)-a.at(1))-abs(a.at(1));
        else if(i == n-1)
        tmp = abs(a.at(n-1))+abs(a.at(n-1)-a.at(n-2))-abs(a.at(n-2));
        else
        tmp = abs(a.at(i)-a.at(i-1))+abs(a.at(i)-a.at(i+1))-abs(a.at(i+1)-a.at(i-1));
        
        cout << sum-tmp << endl;
    }
    return 0;
}