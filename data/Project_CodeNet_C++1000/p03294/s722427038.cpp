#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >>N;
    vector<int>vec1(N);
    for(int i=0;i<N;i++){
        cin>>vec1.at(i);
    }
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=vec1.at(i)-1;
    }
    cout <<sum<<endl;

}