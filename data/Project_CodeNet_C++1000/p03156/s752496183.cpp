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
using namespace std;

int main() {
   int N,A,B;
   cin>>N>>A>>B;
   int X=0;
   int Y=0;
   int Z=0;

    vector<int>P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];
    }
    for(int i=0;i<N;i++){
        if(P[i]<=A){
            X++;
        }
        else if(P[i]>A&&P[i]<=B){
            Y++;
        }
        else{
            Z++;
        }
    }
    cout<<min(X,min(Y,Z))<<endl;
}