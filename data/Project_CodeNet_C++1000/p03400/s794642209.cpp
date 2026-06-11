#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    int d,x;
    cin >> d >> x;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    int ans = x;
    for(int i=0; i<n; i++){
        int temp = (d-1)/vec[i]+1;
        ans+=temp;
    }
    cout << ans <<endl;
}