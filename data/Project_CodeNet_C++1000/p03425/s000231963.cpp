#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    
    string march = "MARCH";
    vector<int> category(march.size(), 0);

    for(int i = 0 ; i < N; i++){
        for(int head = 0; head < march.size(); head++){
            if(S[i][0] == march[head]){
                category[head]++;
            }
        }
    }

    int size = category.size();
    ll totCombi = 0;
    for(int i = 0; i < size - 2; i++){
        for(int j = i + 1; j < size - 1; j++){
            for(int k = j+1; k < size; k++){
                ll combi = (ll)category[i] * (ll)category[j] * (ll)category[k];
                totCombi += combi;
            }
        }
    }

    cout << totCombi << endl;

    return 0;
}
