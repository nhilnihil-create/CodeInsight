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
	int N,M,X;
    cin>>N>>M>>X;
    int ans=0;
    int count=0;

    vector<int>A(M);
    for(int i=0;i<M;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        if(A[i]<X){
            ans++;
        }
        if(A[i]>X){
            count++;
        }
    }
    cout<<min(ans,count)<<endl;
}