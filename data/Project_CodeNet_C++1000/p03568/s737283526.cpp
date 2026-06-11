#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> A;
    int in;
    for (int i = 0; i < N; i++)
    {
        cin >> in;
        A.emplace_back(in);
    }
    
    int all = 1;
    for (int i = 0; i < N; i++)
    {
        all *= 3;
    }
    
    int odd = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            odd *= 2;
        }else
        {
            odd *= 1;
        }
        
    }
    
    cout << all - odd << endl;

    return 0;
}