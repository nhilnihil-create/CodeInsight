#include<iostream>
#include<vector> 
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N;  cin >> N;
    long long bi, sm, cnt, ans;
    vector<int> v(N), u(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    for(int i=0; i<N; i++)  cin >> u[i];

    bi = 0;
    sm = 0;
    cnt = 0;

    for(int i=0; i<N; i++){
        if(v[i] > u[i]){
            bi = bi + v[i] - u[i];
        }
        if(v[i] < u[i]){
            sm = sm + u[i] - v[i];
            if((u[i]-v[i])%2==1)    cnt++;
        }
    }
    if(sm-cnt >= 2*bi)  cout << "Yes";
    else cout << "No";
}