#include <bits/stdc++.h>

using namespace std;

int main()
{
    using T = tuple<string,int,int> ;
    int n,i;

    cin >> n;
    vector<T> rest(n);

    for(i=0; i<n; i++){
        string s;
        int a;
        cin >> s >> a;
        rest.at(i) = T(s,-a,i+1);
    }
    
    sort(rest.begin(),rest.end());

    for(i=0; i<n; i++){
        string S;
        int A;
        int N;
        tie(S,A,N) = rest.at(i);
        cout << N << endl;
    }

    return 0;

}