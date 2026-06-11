#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector< pair < int, int > > pairs(N);
    vector<int> a(N);
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        pairs[i] = make_pair(tmp, i+1);
        a[i]=tmp;
    }
    sort(pairs.begin(), pairs.end());
    if(pairs[0].first>=0){
        cout << N-1 << endl;
        for(int i=0; i<N-1; i++){
            cout << i+1 << ' ' << i+2 << endl;
        }
        return 0;
    }else if(pairs[N-1].first<=0){
        cout << N-1 << endl;
        for(int i=0; i<N-1; i++){
            cout << N-i << ' ' << N-1-i << endl;
        }
        return 0;
    }else if(pairs[0].first+pairs[N-1].first>=0){
        cout << 2*N-2 << endl;
        for(int i=0; i<N; i++){
            if(i+1==pairs[N-1].second) continue;
            cout << pairs[N-1].second << ' ' << i+1 << endl;
        }
        for(int i=0; i<N-1; i++){
            cout << i+1 << ' ' << i+2 << endl;
        }
        return 0;
    }else{
        cout << 2*N-2 << endl;
        for(int i=0; i<N; i++){
            if(i+1==pairs[0].second) continue;
            cout << pairs[0].second << ' ' << i+1 << endl;
        }
        for(int i=0; i<N-1; i++){
            cout << N-i << ' ' << N-1-i << endl;
        }
        return 0;
    }
}