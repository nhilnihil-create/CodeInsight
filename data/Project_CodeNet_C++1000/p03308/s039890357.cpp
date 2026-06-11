#include <algorithm>
#include <iostream>
#include <string>

#include <vector> 

#include <functional>
using namespace std;

#define SIZE_OF_ARRAY(a) (sizeof(a) / sizeof(a[0]))

int main()
{
    int N;
    int *a;
    std::vector<int> data;

    cin >> N;

    a = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        data.push_back(a[i]);
	
    }
   
    std::sort(data.begin(),data.end());//昇順ソート

    cout << data[N-1] - data[0] << endl;

    return 0;
}
