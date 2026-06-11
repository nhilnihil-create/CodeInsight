#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int a[h][w];
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            cin>>a[i][j];
    vector<string> ans;
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            if (a[i][j]%2) {
                stringstream ss;
                if (j==w-1) {
                    if (i!=h-1) {
                        ss<<i+1<<" "<<j+1<<" "<<i+2<<" "<<j+1<<endl;
                        ans.push_back(ss.str());
                        a[i][j]--;
                        a[i+1][j]++;
                    }
                } else {
                    ss<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<endl;
                    ans.push_back(ss.str());
                    a[i][j]--;
                    a[i][j+1]++;
                }
            }
    cout<<ans.size()<<endl;
    for (string s:ans)
        cout<<s;
    return 0;
}