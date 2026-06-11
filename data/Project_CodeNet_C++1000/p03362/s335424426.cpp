#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> pr;
    vector<bool> a(55556);
    for(int i = 2; i < 55556; i++) {
        if(a[i])continue;
        pr.push_back(i);
        for(int j = i; j < 55556; j += i)a[j] = 1;
    }
    int cur = 1;
    reverse(pr.begin(), pr.end());
    while(cur <= n){
        if(pr.back() % 10 == 1){
            cout << pr.back() << endl;
            cur++;
        }
        pr.pop_back();
    }
}