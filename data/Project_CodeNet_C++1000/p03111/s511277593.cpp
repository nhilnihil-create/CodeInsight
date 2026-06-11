#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, A, B, C;
    vector<vector<long long>> ABC(6, vector<long long>(3));
    cin >> N >> A >> B >> C;
    ABC[0][0] = A;
    ABC[0][1] = B;
    ABC[0][2] = C;
    ABC[1][0] = A;
    ABC[1][1] = C;
    ABC[1][2] = B;
    ABC[2][0] = B;
    ABC[2][1] = A;
    ABC[2][2] = C;
    ABC[3][0] = B;
    ABC[3][1] = C;
    ABC[3][2] = A;
    ABC[4][0] = C;
    ABC[4][1] = A;
    ABC[4][2] = B;
    ABC[5][0] = C;
    ABC[5][1] = B;
    ABC[5][2] = A;    
    vector<long long> L(N);
    for(long long i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    long long tmptmpans = 10000;
    for (long long a = 0; a < 6; a++)
    {
        vector<long long> l(N);
        long long ans = 0;
        for(long long i = 0; i < N; i++)
        {
            l[i] = L[i];
        }
        for (long long i = 0; i < 3; i++)
        {
            long long tmpans = 10000;
            vector<long long> tmpcount(l.size());
            for (long long j = 1; j < pow(2,l.size()); j++)
            {
                vector<long long> count(l.size());
                for (long long k = 0; k < l.size(); k++)
                {
                    count[k] = 0;
                }
                long long X = j;
                long long num = 0;
                while(X > 0)
                {
                    if (X & 1)
                    {
                        count[num] = 1;
                    }
                    num++;
                    X >>= 1;
                }
                long long answer = 0;
                long long sum = 0;
                long long countb = 0;
                for (long long k = 0; k < l.size(); k++)
                {
                    
                    if (count[k] == 1)
                    {
                        sum++;
                        countb += l[k];
                    }
                }
                answer += 10 * (sum-1) + abs(ABC[a][i] - countb);
                if (answer < tmpans)
                {
                    tmpans = answer;
                    for (long long k = 0; k < l.size(); k++)
                    {
                        tmpcount[k] = count[k];
                    }
                }
            }
            ans += tmpans;
            for(long long i = 0; i < l.size(); i++)
            {
                if (tmpcount[i] == 1)
                {
                    l[i] = 10000;
                }
            }
        }
        if (tmptmpans > ans)
        {
            tmptmpans = ans;
        }
    }   
    cout << tmptmpans << endl;
}