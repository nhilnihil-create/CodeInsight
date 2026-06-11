#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
using namespace std;
#define INF 1000000005
int main()
{
int n;
std::cin >> n;
std::vector<long long int> a;
for(int i = 0; i < n; i++){
    long long int tempa;
    std::cin >> tempa;
    a.push_back(tempa);
}
int sum = 0;
std::vector<pair<int, int>> output;
int max = a[0];
int min = a[0];
int imax = 0;
int imin = 0;
for(int i = 0; i < n; i++){
    if(a[i] > max){
        max = a[i];
        imax = i;
    }
    if(a[i] < min){
        min = a[i];
        imin = i;
    }
}
if(min >= 0){
    for(int i = 1; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(i - 1,i);
        output.push_back(temp);
    }
} else if(max <= 0){
    for(int i = 1; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(n - i,n - i - 1);
        output.push_back(temp);
    } 
} else if(abs(max) >= abs(min)){
    for(int i = 0; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(imax,i);
        output.push_back(temp);
    }
    for(int i = 1; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(i - 1,i);
        output.push_back(temp);
    }
} else {
    for(int i = 0; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(imin,i);
        output.push_back(temp);
    } 
    for(int i = 1; i < n; i++){
        sum++;
        pair<int,int> temp = make_pair(n - i,n - i - 1);
        output.push_back(temp);
    }  
}


std::cout << sum << std::endl;
for(int i = 0; i < sum; i++){
    std::cout << output[i].first + 1 << " " << output[i].second + 1 << std::endl;
}
return 0;
}