#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    int A=0;

    vector<int>x(N);
    vector<int>y(M);
    for(int i=0;i<N;i++){
        cin>>x[i];
    }
    for(int i=0;i<M;i++){
        cin>>y[i];
    }
    sort(x.begin(), x.end()); 
    reverse(x.begin(), x.end());
    sort(y.begin(), y.end()); 
    
    for(int i=x[0]+1;i<=y[0];i++){
        if(i>X&&i<=Y){
            A=1;
            break;
        }
    }
    
    if(A==1){
        cout<<"No War"<<endl;
    }
    else{
        cout<<"War"<<endl;
    }
}