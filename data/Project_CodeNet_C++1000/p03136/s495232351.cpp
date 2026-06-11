#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;

int main()
{
    int A;
    cin >> A;
    vector<int> input(A);
    int sum = 0;
    int max = 0;
    rep0(i,A){
        cin >> input[i];
        if(max<input[i]){
            max = input[i];
        }
        sum+=input[i];
    }
    if(sum-max>max){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
