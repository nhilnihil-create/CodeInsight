#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;



int main() {
    int N,Ssize;
    cin >> N;
    vector<string>S(N);
    long long ans = 0,Aback=0,Bfront=0,AB=0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> S.at(i);
        Ssize=S.at(i).size();
        
        if (S.at(i).at(0) == 'B' && S.at(i).at(Ssize - 1) == 'A')AB++;
        else {
            if (S.at(i).at(Ssize - 1) == 'A')Aback++;
            if (S.at(i).at(0) == 'B')Bfront++;
        }
        for (size_t j = 0; j < Ssize-1; j++)
        {
            if (S.at(i).substr(j, 2) == "AB")ans++;
        }
        //末尾Aのやつと先頭Bのやつをドッキングさせる。
        //先頭Bのやつが文頭に孤立せざるを得ない状況もありうる。
        
    }
    if (Aback+Bfront == 0&&AB>0)AB--;
    
    ans += AB+min(Aback, Bfront);
    cout << max(ans,0LL);
}