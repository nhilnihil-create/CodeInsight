#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <queue>
#include <fstream>
#include <iterator> // std::back_inserter
#include <chrono>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    int a,b,c;

    cin >> a >> b >> c;
    vector<int> edge = {a,b,c};

    sort(edge.begin(), edge.end(), greater<int>());

    if(edge[0]*edge[0] == edge[1]*edge[2]) cout << "Yes";
    else cout << "No";

    



    return 0;
}
