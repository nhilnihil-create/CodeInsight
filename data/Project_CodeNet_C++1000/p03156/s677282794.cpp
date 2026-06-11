#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, cnta=0, cntab=0, cntb=0;
    cin>>N>>A>>B;

    vector<int> p(N);
    for(int i=0; i<N; i++){
        cin>>p.at(i);
    }

    sort(p.begin(), p.end());

    for(int i=0; i<N; i++){
        if(p.at(i)<=A) cnta++;
        else if(p.at(i)>=A+1 && p.at(i)<=B) cntab++;
        else if(p.at(i)>=B+1) cntb++;
    }

    cout<<min(cnta, min(cntab, cntb))<<endl;
}