#include <iostream>
#include <set>
using namespace std;
int main(int argc, const char *argv[])
{
    set<int> st;
    int x;
    for (int i = 0; i < 3; i++)
    {
        cin >> x;
        st.insert(x);
    }
    if (st.size() == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
