#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int l[n];
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int mincost=INT32_MAX;
    for(int bit = 0; bit < (1<<2*n); bit++) {
        int al=0;
        int bl=0;
        int cl=0;
        int ccost=-3;

        for(int i = 0; i < n; i++) {
            ccost++;
            if((bit&(1<<2*i))&&(bit&(1<<2*i+1))){
                al+=l[i];
            }
            else if((bit&(1<<2*i))&&!(bit&(1<<2*i+1))){
                bl+=l[i];
            }
            else if(!(bit&(1<<2*i))&&(bit&(1<<2*i+1))){
                cl+=l[i];
            }
            else ccost--;
        }
        if(al!=0&&bl!=0&&cl!=0){
            int cost=abs(a-al)+abs(b-bl)+abs(c-cl)+ccost*10;
            mincost=min(mincost,cost);
        }
    }
    cout << mincost << "\n";
    return 0;
}