#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll bucket[5] = {0};

int main() {
    int n; 
    cin >> n;

    int p[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    int q[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
    int r[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

    for(int i=0; i<n; i++){
        string s;
        cin>>s;

        if(s[0]=='M'){
            bucket[0]++;
        }else if(s[0]=='A'){
            bucket[1]++;
        }else if(s[0]=='R'){
            bucket[2]++;
        }else if(s[0]=='C'){
            bucket[3]++;
        }else if(s[0]=='H'){
            bucket[4]++;
        }
    }

    ll ans = 0;
    for(int i=0; i<10; i++){
        ans += bucket[p[i]] * bucket[q[i]] * bucket[r[i]];
    }

    cout<< ans <<endl;
    return 0;
}