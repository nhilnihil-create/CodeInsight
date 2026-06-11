#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int N;
    cin >> N;
    int res[N+1]={};
    rep1(i,N){
        int tmp = i;
        while(tmp<=N){
            res[tmp]++;
            tmp+=i;
        }
    }
    int out=0;
    rep1(i,N){
        if(i%2==1&&res[i]==8){
            out++;
        }
    }
    cout << out << endl;
}
