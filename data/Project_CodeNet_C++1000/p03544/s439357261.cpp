#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int64_t>vec(87);
    vec.at(0)=2;
    vec.at(1)=1;
    for(int i=2;i<=86;i++){
        vec.at(i)=vec.at(i-1)+vec.at(i-2);
    }
    cout<<vec.at(n)<<endl;
}