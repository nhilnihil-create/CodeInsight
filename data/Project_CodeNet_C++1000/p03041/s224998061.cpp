#include <iostream>

using namespace std;

int main()
{
   string S ;
    int N , K ;
    cin >> N >> K >> S ;
    K = K - 1 ;
    if(S[K] == 'A')
    {
       S[K] = 'a';
       cout << S << endl;
    }
    if(S[K] == 'B')
    {
        S[K] = 'b';
        cout << S << endl;
    }
    if(S[K] == 'C')
    {
        S[K] = 'c' ;
        cout << S << endl;
    }

    return 0;
}
