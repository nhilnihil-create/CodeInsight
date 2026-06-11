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
   string S;
   cin>>S;
   string A=S.substr(2,S.size()-3);
   
   int ans=0;
   int count=0;

   for(int i=0;i<A.size();i++){
       if(A[i]=='C'){
           ans++;
       }
   }
   for(int i=0;i<S.size();i++){
       if(S[i] >= 'a' && S[i] <= 'z'){
           count++;
       }
   }

   if(S[0]=='A'&&ans==1&&count==S.size()-2){
       cout<<"AC"<<endl;
   }
   else{
       cout<<"WA"<<endl; 
   }
}