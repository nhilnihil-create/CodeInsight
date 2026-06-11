#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

int sum(int x){
    int res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int answer = 1e9;
    for(int a = 1; a < n; a++){
        int res = sum(a) + sum(n-a);
        answer = min(answer, res);
    }

    cout << answer << endl;
}
