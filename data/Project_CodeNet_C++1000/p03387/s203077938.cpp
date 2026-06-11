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
    int input[3];
    cin >> input[0] >> input[1] >> input[2];
    sort(input,input+3);
    int diff = input[2]*2 - input[1] - input[0];
    if(diff%2==0){
        cout << diff/2 << endl;
    }else{
        cout << diff/2 + 2 << endl;
    }
}
