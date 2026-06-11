#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100000000

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ecount = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'E')
        {
            ecount++;
        }
        
    }
    
    int people = 0;
    int e_people = 0;
    int w_people = 0;
    for (int i = 0; i < N; i++)
    {
        int now = 0;
        if (S[i] == 'E')
        {
            w_people = N - ecount - (i - e_people);
        } else
        {
            w_people = N - ecount - (i + 1 - e_people);
        }
        now = e_people + w_people;
        people = max(now, people);
        if (S[i] == 'E')
        {
            e_people++;
        }
        
        
    }

    cout << N - people - 1 << endl;
    return 0;
}