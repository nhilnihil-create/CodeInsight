#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
    string s;
    cin >> s;
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');
    if((a == 0 || a >= 13) && (b == 0 || b >= 13)){
        cout << "NA" << endl;
    }else if(a == 0 || a >= 13){
        cout << "YYMM" << endl;
    }else if(b == 0 || b >= 13){
        cout << "MMYY" << endl;
    }else{
        cout << "AMBIGUOUS" << endl;
    }
}