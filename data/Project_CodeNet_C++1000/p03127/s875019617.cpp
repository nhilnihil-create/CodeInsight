#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if( b == 0) return a;
    else return gcd(b,a%b);    
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for(int i=0; i<N; i++){
        cin >> A.at(i);
        if(i > 0)
        A.at(i) = gcd(A.at(i),A.at(i-1));
    }

    cout << A.at(N-1) << endl;
    return 0;
}