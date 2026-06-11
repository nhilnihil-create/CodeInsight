#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //input
    long long N;
    cin >> N;
    vector<long long> A_vec;
    long long A;
    long long i;
    for(i=1; i<=N; i++){
        cin >> A;
        A_vec.push_back(A-i);
    }

    //calc
    sort(A_vec.begin(),A_vec.end());
    A = A_vec[N/2];
    long long ans=0;
    for(i=0; i<A_vec.size(); i++){
        ans += abs(A-A_vec[i]);
    }

    //answer
    cout << ans << endl;
    system("pause");
    return 0;
}