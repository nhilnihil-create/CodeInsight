#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

//pdf見て回答

int main(){
    int n, k, mini = 0, ans = 1e9;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i] == 1){ mini = i; }
    }

    /*
    mini++;
    for(int i = -k + 1; i < 1; i++){
        int left = mini + i;
        int right = left + k - 1;
        if(left < 1 || right > n) continue;
        int leftNum = (left - 1) / (double)(k - 1) + 0.5;
        int rightNum = (n - right) / (double)(k - 1) + 0.5;
        if(leftNum < 0) leftNum = 0;
        if(rightNum < 0) rightNum = 0;
        ans = min(ans, leftNum + rightNum + 1);
        //cout << left << " " << right << endl;
        //cout << leftNum << " " << rightNum << endl;
        //cout << "---" << endl;
    }*/

    ans = (n - 2) / (k - 1) + 1;

    put(ans);
}