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
    int N;
    cin >> N;

    char a;

    int R=0, B=0;

    for(int i=0; i<N; i++){
        cin >> a;
        if(a == 'R') R++;
        else B++;
    }

    if(R>B) cout << "Yes";
    else cout << "No";

    return 0;
}