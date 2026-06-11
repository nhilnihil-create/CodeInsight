#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for(int i = 0; i <n; i++){
        cin >> p[i];
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 0; i <n; i++){
        p[i] <= a ? cnt1++ :p[i] > a && p[i] <= b ? cnt2++ : cnt3++;
    }
    cout << min({cnt1,cnt2,cnt3});
}