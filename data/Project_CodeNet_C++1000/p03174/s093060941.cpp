
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long mod = 1e9+7;
    int N; cin >> N;
    vector < vector <int> > pairings(N, vector<int>(N));
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            cin >> pairings[i][j];
        }
    }
    vector < long long> numberOfPairings(1<<N);
    numberOfPairings[0]=1;
    for (int i=0; i<(1<<N); ++i)
    {
        int assigned=0;
        for (int j=0; j<N; ++j)
        {
            if ((1<<j) & i) assigned++;
        }
        for (int j=0; j<N; ++j)
        {
            if ((1<< j) &i) continue;
            if (pairings[assigned][j]) 
                numberOfPairings[i | (1<<j)] = (numberOfPairings[i | (1 << j)] + numberOfPairings[i])%mod;
		}
	}
	cout << numberOfPairings[(1<<N)-1] << "\n";
}
