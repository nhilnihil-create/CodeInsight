#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n;
    std::deque<long long int> A;
    for (int i=0;i<n;i++) {
        cin>>a;
        A.emplace_back(a);
    }
    std::deque<long long int> B;
    for (int i=0;i<n;i++) {
        cin>>b;
        B.emplace_back(b);
    }
    std::deque<long long int> C;
    long long int tmp=0,count=0;
    int flag=0;
    for (int i=0;i<n;i++) {
        if (A[i]<B[i]) {
            flag=1;
        }
        if (A[i]-B[i]<0) {
            tmp+=A[i]-B[i];
            count++;
        } else if (A[i]-B[i]>0) {
            C.emplace_back(A[i]-B[i]);
        }
    }
    if (flag==0) {
        cout<<0<<endl;
    } else {
        sort(C.begin(),C.end(),greater<long long int>());
        for (int i=0;i<C.size();i++) {
            if (C[i]+tmp>=0) {
                cout<<count+i+1<<endl;
                return 0;
            } else {
                tmp+=C[i];
            }
        }
        cout<<-1<<endl;
    }
}