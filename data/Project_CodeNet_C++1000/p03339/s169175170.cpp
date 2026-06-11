#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(){
    ll N;
    std::string str;

    std::cin >> N;
    std::cin >> str;

    vector<int> A(N, 0);

    for(int i=1;i<str.size();i++)
    {

        if(str[i-1] == 'W')
        {
            A[i] = A[i-1] + 1;
        }else
        {
            A[i] = A[i-1];
        }
        
    }

    ll tmpValue = 0;
    for(int i=(str.size()-2);i>=0;i--)
    {
        if(str[i+1] == 'E')
        {
            tmpValue++;
        }        
        A[i] += tmpValue;
    }

    std::sort(A.begin(), A.end());
    std::cout << A[0];

    return 0;
}


