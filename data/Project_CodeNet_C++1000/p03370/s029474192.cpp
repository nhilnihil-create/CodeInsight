#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i=0; i<N; i++)
    {
        cin >> A.at(i);
    }
    int count=A.size();
    int chk=0;
    for(int i=0; i<N; i++)
    {
        chk+=A.at(i);
    }
    sort(A.begin(),A.end());
    while(chk<M)
    {
        chk+=A.at(0);
        if(chk>M) break;
        count++;
    }
    cout << count << endl;
}