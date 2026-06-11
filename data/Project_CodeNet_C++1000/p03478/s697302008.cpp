#include <bits/stdc++.h>
using namespace std;


int main() {

    int64_t n,a,b;
    cin>>n>>a>>b;

    int64_t sum_all=0;
    for(int i=1;i<=n;i++){
        string swk = to_string(i);
        int64_t sum=0;
        for(int j=0;j<swk.size();j++){
            char cwk = swk.at(j);
            sum+=(cwk-'0');
        }
        if(sum>=a&&sum<=b)
            sum_all+=i;
    }

    cout<<sum_all<<endl;

	return 0;
}