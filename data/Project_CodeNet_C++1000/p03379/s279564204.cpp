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
    int n;
    cin >> n;
    int input[n],clo[n];
    rep0(i,n){
        cin >> input[i];
        clo[i] = input[i];
    }
    sort(clo,clo+n);
    int left = clo[n/2-1];
    int right = clo[n/2];
    rep0(i,n){
        if(input[i]<=left){
            cout << right << endl;
        }else{
            cout << left << endl;
        }
    }
}
