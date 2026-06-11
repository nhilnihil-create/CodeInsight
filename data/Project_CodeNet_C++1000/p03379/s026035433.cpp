#include <bits/stdc++.h>
using namespace std;
int main()
{
int N;
cin >> N;
vector<int> A(N);
vector<int> B(N);
for(int i=0; i<N; i++)
{
    cin >> A.at(i);
    B.at(i)=A.at(i);
}
int median, downmedian, upmedian;
sort(A.begin(),A.end());
downmedian=A.at((N/2)-1);
upmedian=A.at(N/2);
for(int i=0; i<N; i++)
{
if(B.at(i)>=upmedian) cout << downmedian << endl;
else cout << upmedian << endl;
}
}