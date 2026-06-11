#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for(int i = 0;i < m;i++)cin >> a.at(i);
    int ans1 = 0, ans2 = 0;
    for(int i = 0;i < m;i++){
        if(a.at(i) <= x)ans1++;
        else ans2++;
    }
    cout << min(ans1, ans2) << endl;
}