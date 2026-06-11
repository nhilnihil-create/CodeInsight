#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<tuple<string, int, int>> guide_book(n);
    for (int i=0; i<n; i++)
    {
        string shop_name;
        int point;
        cin >> shop_name >> point;
        guide_book.at(i) = make_tuple(shop_name, point, i+1);
    }

    sort(guide_book.begin(), guide_book.end());

    vector<tuple<string, int, int>> a(n);
    for (int i=0; i<n;)
    {
        a.at(0) = make_tuple(get<0>(guide_book.at(i)), get<1>(guide_book.at(i)), get<2>(guide_book.at(i)));
        i++;
        int j = 1;
        while (i < n && get<0>(a.at(0)) == get<0>(guide_book.at(i)))
        {
            a.at(j) = make_tuple(get<0>(guide_book.at(i)), get<1>(guide_book.at(i)), get<2>(guide_book.at(i)));
            i++; j++;
        }
        for (j-=1; j>=0; j--)
        {
            cout << get<2>(a.at(j)) << endl;
        }
    }
}