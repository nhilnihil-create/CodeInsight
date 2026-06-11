#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,L;
    cin >> N;
    int sum=0,m=0; 

    for(int i=0; i<N; i++){
        cin >> L;
        m = max(m,L);
        sum += L;
    }

    if(m < sum-m)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}