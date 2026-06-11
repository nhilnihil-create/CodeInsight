#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;


int main()
{
    int N;
    N = 3;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    

    string result = "No";

    if (A.at(0) == A.at(1) && A.at(1) == A.at(2))
    {
        result = "Yes";
    }
    
    cout << result;

    return 0;
}
