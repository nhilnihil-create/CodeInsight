#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    string S;
    int offs = 97;
    
    vector<int> xspec(26), yspec(26);

    cin >> N >> S;

    int overlaps = 0;
    for(int cut = 1; cut < N; cut++){
        for(int i = 0; i < cut; i++){
            xspec[(int) S[i]-offs] = 1;
        }
        for(int i = cut; i < N; i++){
            yspec[(int) S[i]-offs] = 1;
        }
        int val = 0;
        for(int i = 0; i < 26; i++){
            if(xspec[i] > 0 && yspec[i] > 0){
                val++;
            }
        }
        if(val > overlaps) overlaps = val;

        fill(xspec.begin(), xspec.end(), 0);
        fill(yspec.begin(), yspec.end(), 0);
    }

    cout << overlaps << endl;

    return 0;
}
