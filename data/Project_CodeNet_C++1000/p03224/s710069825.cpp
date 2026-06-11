#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int,int> pi;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int j = sqrt(1+8*n);
    if (j*j != (8*n+1)) cout<<"No\n";
    else {
        if (j%2==0) cout<<"No\n";
        else {
            int k = (1+j)/2;
            cout<<"Yes"<<"\n"<<k;
            vector<int> v[k];
            for (int i=0,ct=1;i<k;i++) {
                for (int j=0;j<i;j++,ct++) {
                    v[i].push_back(ct);
                    v[j].push_back(ct);
                }
            }
            for (int i=0;i<k;i++) {
                cout<<"\n"<<v[i].size();
                for (auto it:v[i]) {
                    cout<<" "<<it;
                }
            }
        }
    }
}
